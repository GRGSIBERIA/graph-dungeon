//
//  Graph.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/14.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Graph_hpp
#define DungeonMaker_Graph_hpp

#include <memory>
#include "Grid.hpp"

namespace dungeon
{
    class Graph;
    typedef std::shared_ptr<Graph> GraphPtr;
    
    class Graph
    {
        Rect rect;
        GraphPtr lhs;
        GraphPtr rhs;
        
    public:
        Graph(Grid& grid, int initDivX, int initDivY)
        : rect(initDivX * grid.AreaWidth(),
               initDivY * grid.AreaHeight(),
               grid.AreaWidth(), grid.AreaHeight())
        {
            
        }
    };
}

#endif
