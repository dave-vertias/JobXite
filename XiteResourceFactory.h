#pragma once

#include "IReasourceFactory.h"

class XiteResourceFactory: public IResourceFactory {

    public:

        XiteResourceFactory();
        shared_ptr<Resource> get_resource() const final;

    private:
        
        shared_ptr<Resource> _resource;
};
