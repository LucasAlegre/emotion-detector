#include "Node.h"
#include "Trie.h"

using namespace std;

Trie::Trie()
{
    root = new Node();
}

Trie::~Trie()
{
    // Free memory
}

void Trie::addWord(string s)
{
    Node* current = root;

    if ( s.length() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {        
        Node* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 )
            current->setWordMarker();
    }
}


bool Trie::searchWord(string s)
{
    Node* current = root;

    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        if ( current->wordMarker() )
            return true;
        else
            return false;
    }

    return false;
}
void Trie::printAllPossibleChildren(Node* node, string s){
            
            string aux = s + node->content();
            if ( node->children().size()==0 ){
                cout << aux << endl;
                return;
            }else{
                for(int i = 0; i<node->children().size(); i++){
                    printAllPossibleChildren(node->children().at(i), aux);
                }
            }
}

void Trie::findRadOccurances(string rad){


    Node* current = root;

        for ( int i = 0; i < rad.length(); i++ )
        {
            Node* tmp = current->findChild(rad[i]);
            if ( tmp == NULL ){
                cout << "No word has been found with that Rad" << endl;
                return;
            }
            current = tmp;
        }
    

        for(Node* no : current->children()){
                printAllPossibleChildren(no, rad);
                }

    return;

}
