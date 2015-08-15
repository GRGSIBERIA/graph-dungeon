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

namespace dungeon
{
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
            for (const auto& s : section)
                s.resize(numWidth, 0);
        }
        
        std::vector<int>& operator[](int h) { return section[h]; }
        
        int Width() const { return numWidth; }
        int Height() const { return numHeight; }
    };
}

#endif
