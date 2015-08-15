//
//  Section.cpp
//  DungeonGenerator
//
//  Created by Eiichi Takebuchi on 2015/08/15.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#include "Section.hpp"

int dungeon::Section::CheckPoint(const Point& pt)
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