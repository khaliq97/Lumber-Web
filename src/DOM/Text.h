#ifndef TEXT_H
#define TEXT_H
#include <DOM/CharacterData.h>
#include <string>
class Text : public CharacterData
{
    public:
        Text(std::shared_ptr<Node> parentNode);
};

#endif // TEXT_H
