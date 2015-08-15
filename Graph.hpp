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
#include "Section.hpp"

namespace dungeon
{
    class Graph;
    typedef std::shared_ptr<Graph> GraphPtr;
    
    class Graph
    {
        Point point;
        GraphPtr lhs;
        GraphPtr rhs;
        
    public:
        Graph(Section& section)
        lhs(nullptr), rhs(nullptr)
        {
            
        }
    };
}

#endif
