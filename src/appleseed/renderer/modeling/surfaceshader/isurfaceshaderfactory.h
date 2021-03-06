
//
// This source file is part of appleseed.
// Visit https://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2018 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_RENDERER_MODELING_SURFACESHADER_ISURFACESHADERFACTORY_H
#define APPLESEED_RENDERER_MODELING_SURFACESHADER_ISURFACESHADERFACTORY_H

// appleseed.foundation headers.
#include "foundation/core/concepts/iunknown.h"
#include "foundation/utility/autoreleaseptr.h"

// appleseed.main headers.
#include "main/dllsymbol.h"

// Forward declarations.
namespace foundation    { class Dictionary; }
namespace foundation    { class DictionaryArray; }
namespace renderer      { class ParamArray; }
namespace renderer      { class SurfaceShader; }

namespace renderer
{

//
// Surface shader factory interface.
//

class APPLESEED_DLLSYMBOL ISurfaceShaderFactory
  : public foundation::IUnknown
{
  public:
    // Return a string identifying this surface shader model.
    virtual const char* get_model() const = 0;

    // Return metadata for this surface shader model.
    virtual foundation::Dictionary get_model_metadata() const = 0;

    // Return metadata for the inputs of this surface shader model.
    virtual foundation::DictionaryArray get_input_metadata() const = 0;

    // Create a new surface shader instance.
    virtual foundation::auto_release_ptr<SurfaceShader> create(
        const char*         name,
        const ParamArray&   params) const = 0;
};

}       // namespace renderer

#endif  // !APPLESEED_RENDERER_MODELING_SURFACESHADER_ISURFACESHADERFACTORY_H
