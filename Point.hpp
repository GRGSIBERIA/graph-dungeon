//
//  Point.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/15.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Point_hpp
#define DungeonMaker_Point_hpp

namespace dungeon
{
    class Point
    {
    public:
        int x, y;
        
        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) { }
        Point(const Point& point) : x(point.x), y(point.y) { }
    };
}

#endif
