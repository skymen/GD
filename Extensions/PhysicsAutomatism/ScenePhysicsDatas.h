/**

Game Develop - Physic Automatism Extension
Copyright (c) 2010 Florian Rival (Florian.Rival@gmail.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

*/

#ifndef SCENEPHYSICSDATAS_H
#define SCENEPHYSICSDATAS_H

#include "Box2D/Box2D.h"
#include "GDL/AutomatismsSharedDatas.h"
#include "RuntimeScenePhysicsDatas.h"
#include <iostream>

/**
 * Datas shared by Physics Automatism
 */
class ScenePhysicsDatas : public AutomatismsSharedDatas
{
    public:
        ScenePhysicsDatas(std::string typeName) : AutomatismsSharedDatas(typeName), gravityX(0), gravityY(0), scaleX(100), scaleY(100)
        {
        };
        virtual ~ScenePhysicsDatas() {};
        virtual boost::shared_ptr<AutomatismsSharedDatas> Clone() { return boost::shared_ptr<AutomatismsSharedDatas>(new ScenePhysicsDatas(*this));}

        float gravityX;
        float gravityY;
        float scaleX;
        float scaleY;

        virtual boost::shared_ptr<AutomatismsRuntimeSharedDatas> CreateRuntimeSharedDatas()
        {
            return boost::shared_ptr<AutomatismsRuntimeSharedDatas>(new RuntimeScenePhysicsDatas(*this));
        }

        #if defined(GDE)
        virtual void SaveToXml(TiXmlElement * eventElem) const;
        #endif

        virtual void LoadFromXml(const TiXmlElement * eventElem);

    private:
};

#endif // SCENEPHYSICSDATAS_H