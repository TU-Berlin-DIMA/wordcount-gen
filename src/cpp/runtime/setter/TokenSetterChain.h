#ifndef TOKENSETTERCHAIN_H_
#define TOKENSETTERCHAIN_H_

#include "runtime/setter/base/BaseTokenSetterChain.h"

using namespace Myriad;

namespace WordCountGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class TokenSetterChain : public BaseTokenSetterChain
{
public:

    TokenSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        BaseTokenSetterChain(opMode, random, config)
    {
    }

    virtual ~TokenSetterChain()
    {
    }
};

} // namespace WordCountGen

#endif /* BASETOKENGENERATOR_H_ */
