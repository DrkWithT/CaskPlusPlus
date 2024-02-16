#ifndef CASK_AST_ENUMS_HPP
#define CASK_AST_ENUMS_HPP

namespace cask::syntax
{
    enum CaskDataType
    {
        datatype_bool,
        datatype_int,
        datatype_float,
        datatype_string,
        datatype_xarray,
        datatype_aggregate
    };
}

#endif