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

int dungeon::Section::DecideDirection(int directionFlag, std::random_device& rd)
{
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
        if (directionFlag & 1 << i) cnt++;
    
    int decide = std::uniform_int_distribution<int>(1, cnt)(rd);
        
    int retval = 0;
    int c = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (directionFlag & 1 << i) ++c;
        
        if (c == decide)
        {
            retval = 1 << i;
            break;
        }
    }
    
    return retval;
}

dungeon::Point dungeon::Section::ConnectTo(const Point& pt, std::random_device& rd)
{
    int num = CheckPoint(pt);
    num = DecideDirection(num, rd);
    
    dungeon::Point retval(pt);
    switch ((dungeon::Direction)num) {
        case dungeon::Direction::Left:
            --retval.x;
            break;
            
        case dungeon::Direction::Right:
            ++retval.x;
            break;
            
        case dungeon::Direction::Up:
            --retval.y;
            break;
        
        case dungeon::Direction::Down:
            ++retval.y;
            break;
    }
    return retval;
}