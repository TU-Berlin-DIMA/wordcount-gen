#ifndef TOKEN_H_
#define TOKEN_H_

#include "record/base/BaseToken.h"

using namespace Myriad;

namespace WordCountGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Token: public BaseToken
{
public:

    Token(const TokenMeta& meta)
        : BaseToken(meta)
    {
    }

};

} // namespace WordCountGen

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<WordCountGen::Token>::CollectorType::serialize(OutputTraits<WordCountGen::Token>::CollectorType::StreamType& out, const WordCountGen::Token& record)
{
    out << record.valueEnumValue() << record.separatorEnumValue();
}

} // namespace Myriad

#endif /* TOKEN_H_ */
