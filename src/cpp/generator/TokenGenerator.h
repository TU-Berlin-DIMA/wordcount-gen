#ifndef TOKENGENERATOR_H_
#define TOKENGENERATOR_H_

#include "generator/base/BaseTokenGenerator.h"

using namespace Myriad;

namespace WordCountGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class TokenGenerator: public BaseTokenGenerator
{
public:

    typedef RecordTraits<Token>::SetterChainType SetterChainType;

    TokenGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseTokenGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace WordCountGen

#endif /* BASETOKENGENERATOR_H_ */
