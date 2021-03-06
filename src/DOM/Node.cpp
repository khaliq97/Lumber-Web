#include <DOM/Node.h>
#include <DOM/Document.h>
#include <DOM/Text.h>
#include <Parser/Lexer.h>
static Lexer lexer;
Node::Node()
{
    nodeType = Node::NodeType::ElementNode;
    nodeName = "";
    baseURI = "";
    isConnected = false;
    nodeValue = "";
    textContent = "";
}

Node::Node(std::shared_ptr<Node> parentNode) : parentNode(parentNode)
{
    nodeType = Node::NodeType::ElementNode;
    nodeName = "";
    baseURI = "";
    isConnected = false;
    nodeValue = "";
    textContent = "";
}

Node::~Node()
{
}

std::string Node::getTextContent()
{
    std::string returnStr = "";
    for (auto node: childNodes)
    {
        if (auto textNode = dynamic_cast<class Text*>(node.get()))
        {
            if (!textNode->data.empty())
            {
                returnStr += textNode->data;
            }
        }
    }
    return returnStr;
}

std::vector<std::shared_ptr<Node> > Node::getAllNodes(std::vector<std::shared_ptr<Node>> returnNodes, std::shared_ptr<Node> node)
{
    returnNodes.push_back(node);

    for (int i = 0; i < node->childNodes.size(); i++)
    {
        returnNodes = getAllNodes(returnNodes, node->childNodes[i]);
    }

    return returnNodes;
}

