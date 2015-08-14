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
        int divW, divH;
        int areaW, areaH;
        
    public:
        /**
         * @brief Grid class
         * @param[in] divW a division of width for a floor
         * @param[in] divH a division of height for a floor
         * @param[in] areaW an area of width on a division
         * @param[in] areaH an area of height on a division
         */
        Grid(int divW, int divH, int areaW, int areaH)
        :
        width(divW * areaW), height(divH * areaH),
        divW(divW), divH(divH),
        areaW(areaW), areaH(areaH)
        {
            grid.resize(height);
            for (const auto& g : grid)
                g.resize(width);
        }
        
        int Width() const { return width; }
        int Height() const { return height; }
        int DivisionWidth() const { return divW; }
        int DivisionHeight() const { return divH; }
        int AreaWidth() const { return areaW; }
        int AreaHeight() const { return areaH; }
        
        std::vector<int>& operator[](int height) { return grid[height]; }
    };
}

#endif
