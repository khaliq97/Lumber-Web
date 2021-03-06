#ifndef COMPOUNDSELECTOR_H
#define COMPOUNDSELECTOR_H
#include <CSS/Selectors/SimpleSelector.h>
#include <memory>
#include <vector>
class CompoundSelector
{
public:
    CompoundSelector();
    std::shared_ptr<TypeSelector> typeSelector;
    std::vector<std::shared_ptr<SimpleSelector>> subClassSelectors;
};

#endif // COMPOUNDSELECTOR_H
