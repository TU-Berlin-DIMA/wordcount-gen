// auto-generatad C++ file for `token`

#ifndef BASETOKEN_H_
#define BASETOKEN_H_

#include "record/Record.h"
#include "record/TokenMeta.h"

using namespace Myriad;

namespace WordCountGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Token;
class TokenConfig;
class TokenGenerator;
class TokenSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseToken: public Record
{
public:

    BaseToken(const TokenMeta& meta) : 
        _meta(meta)
    {
    }

    const TokenMeta& meta() const
    {
        return _meta;
    }

    void value(const Enum& v);
    const Enum& value() const;
    const String& valueEnumValue() const;

    void separator(const Enum& v);
    const Enum& separator() const;
    const String& separatorEnumValue() const;

protected:

    // meta
    const TokenMeta& _meta;

    // fields
    Enum _value;
    Enum _separator;
};

inline void BaseToken::value(const Enum& v)
{
    _value = v;
}

inline const Enum& BaseToken::value() const
{
    return _value;
}

inline const String& BaseToken::valueEnumValue() const
{
    return _meta.value[_value];
}

inline void BaseToken::separator(const Enum& v)
{
    _separator = v;
}

inline const Enum& BaseToken::separator() const
{
    return _separator;
}

inline const String& BaseToken::separatorEnumValue() const
{
    return _meta.separator[_separator];
}

} // namespace WordCountGen

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<WordCountGen::Token>
{
    typedef WordCountGen::TokenMeta MetaType;
    typedef WordCountGen::TokenGenerator GeneratorType;
    typedef WordCountGen::TokenSetterChain SetterChainType;
    typedef RecordFactory<WordCountGen::Token> FactoryType;

    enum Field { UNKNOWN, GEN_ID, VALUE, SEPARATOR };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<WordCountGen::BaseToken>::CollectorType::serialize(OutputTraits<WordCountGen::Token>::CollectorType::StreamType& out, const WordCountGen::BaseToken& record)
{
    write(out, record.valueEnumValue(), false);
    out << '|';
    write(out, record.separatorEnumValue(), false);
    out << '|';
    out << '\n';
}

} // namespace Myriad

#endif /* BASETOKEN_H_ */
