//
//  Grid.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/14.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Grid_hpp
#define DungeonMaker_Grid_hpp

#include <vector>

namespace dungeon
{
    class Grid
    {
        std::vector<std::vector<int>> grid;
        int width, height;
        
    public:
        Grid(int w, int h)
        : width(w), height(h)
        {
            grid.resize(h);
            for (const auto& g : grid)
                g.resize(w);
        }
        
        int Width() const { return width; }
        int Height() const { return height; }
        
        std::vector<int>& operator[](int height) { return grid[height]; }
    };
}

#endif
