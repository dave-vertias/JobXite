#include "XiteResourceFactory.h"


XiteResourceFactory::XiteResourceFactory() {
    _resource = make_shared<Resource>();
    _resource->set_path{};

    _resource->set_method_handler();
}

