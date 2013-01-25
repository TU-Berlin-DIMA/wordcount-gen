// auto-generatad C++ generator for `token`

#ifndef BASETOKENGENERATOR_H_
#define BASETOKENGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/TokenSetterChain.h"

using namespace Myriad;

namespace WordCountGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseTokenGenerator: public RandomSequenceGenerator<Token>
{
public:

    BaseTokenGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        RandomSequenceGenerator<Token>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const GeneratorPool& pool)
    {
        // call generator implementation
        RandomSequenceGenerator<Token>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new PartitionedSequenceIteratorTask< Token > (*this, _config));
        }
    }

    TokenSetterChain setterChain(BaseSetterChain::OperationMode opMode, RandomStream& random)
    {
        return TokenSetterChain(opMode, random, _config);
    }
};

} // namespace WordCountGen

#endif /* BASETOKENGENERATOR_H_ */
