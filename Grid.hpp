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
#include "Section.hpp"

namespace dungeon
{
    class Grid
    {
        std::vector<std::vector<int>> grid;
        
        int width, height;
        int areaW, areaH;
        
    public:
        /**
         * @brief Grid class
         * @param[in] divW number of a division on a floor
         * @param[in] divH number of a division on a floor
         * @param[in] areaW width on an area
         * @param[in] areaH height on an area
         */
        Grid(const Section& section, int areaW, int areaH)
        :
        width(section.Width() * areaW), height(section.Height() * areaH),
        areaW(areaW), areaH(areaH)
        {
            grid.resize(height);
            for (const auto& g : grid)
                g.resize(width, 0);
        }
        
        int Width() const { return width; }
        int Height() const { return height; }
        int AreaWidth() const { return areaW; }
        int AreaHeight() const { return areaH; }
        
        std::vector<int>& operator[](int height) { return grid[height]; }
    };
}

#endif
