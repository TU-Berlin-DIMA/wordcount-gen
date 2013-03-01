#ifndef TOKENGENERATOR_H_
#define TOKENGENERATOR_H_

#include "generator/base/BaseTokenGenerator.h"

namespace WordCountGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class TokenGenerator: public BaseTokenGenerator
{
public:

    typedef Myriad::RecordTraits<Token>::SetterChainType SetterChainType;

    TokenGenerator(const string& name, Myriad::GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseTokenGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace WordCountGen

#endif /* BASETOKENGENERATOR_H_ */
