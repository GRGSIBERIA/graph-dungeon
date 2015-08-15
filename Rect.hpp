//
//  Rect.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/14.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Rect_hpp
#define DungeonMaker_Rect_hpp

namespace dungeon
{
    class Rect
    {
    public:
        int x, y, width, height;
        
        Rect(int x, int y, int w, int h)
        : x(x), y(y), width(w), height(h) {}
        Rect() : x(0), y(0), width(0), height(0) {}
        Rect(const Rect& r) : x(r.x), y(r.y), width(r.width), height(r.height) {}
    };
}

#endif
