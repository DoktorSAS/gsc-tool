// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "h2.hpp"

namespace xsk::gsc::h2
{

void context::init(build mode, read_cb_type callback)
{
    compiler_.mode(mode);
    resolver::init(callback);
}

void context::cleanup()
{
    resolver::cleanup();
}

} // namespace xsk::gsc::h2
