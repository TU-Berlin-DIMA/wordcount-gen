// auto-generatad C++ file for `token`

#ifndef BASETOKENUTIL_H_
#define BASETOKENUTIL_H_

#include "record/Token.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// value
template<>
struct RecordFieldTraits<RecordTraits<WordCountGen::Token>::VALUE, WordCountGen::Token>
{
    typedef Enum FieldType;
    typedef MethodTraits<WordCountGen::Token, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<WordCountGen::Token, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&WordCountGen::Token::value);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&WordCountGen::Token::value);
    }
};

// separator
template<>
struct RecordFieldTraits<RecordTraits<WordCountGen::Token>::SEPARATOR, WordCountGen::Token>
{
    typedef Enum FieldType;
    typedef MethodTraits<WordCountGen::Token, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<WordCountGen::Token, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&WordCountGen::Token::separator);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&WordCountGen::Token::separator);
    }
};

} // namespace Myriad

#endif /* BASETOKENUTIL_H_ */
