//
//  Section.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/15.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Section_hpp
#define DungeonMaker_Section_hpp

#include <vector>
#include <memory>
#include "Point.hpp"

namespace dungeon
{
    enum class Direction
    {
        Left = 0x01,
        Right = 0x02,
        Up = 0x04,
        Down = 0x08
    };
    
    class Section;
    typedef std::shared_ptr<Section> SectionPtr;
    
    class Section
    {
        std::vector<std::vector<int>> section;
        int numWidth;
        int numHeight;
        
    public:
        
        Section(int numWidth, int numHeight)
        : numWidth(numWidth), numHeight(numHeight)
        {
            section.resize(numHeight);
            for (int i = 0; i < numHeight; ++i)
                section[i].resize(numWidth, 0);
        }
        
        std::vector<int>& operator[](int h) { return section[h]; }
        
        int Width() const { return numWidth; }
        int Height() const { return numHeight; }
        
        int CheckPoint(const Point& pt)
        {
            int x, y, flags = 0;
            
            y = pt.y;
            
            // left
            x = pt.x - 1;
            if (x >= 0 && x < numWidth && section[y][x] == 0)
                flags |= (int)Direction::Left;
            
            // right
            x = pt.x + 1;
            if (x >= 0 && x < numWidth && section[y][x] == 0)
                flags |= (int)Direction::Right;
            
            x = pt.x;
            
            // up
            y = pt.y - 1;
            if (y >= 0 && y < numHeight && section[y][x] == 0)
                flags |= (int)Direction::Up;
            
            // down
            y = pt.y + 1;
            if (y >= 0 && y < numHeight && section[y][x] == 0)
                flags |= (int)Direction::Down;
            
            return flags;
        }
    };
}

#endif
