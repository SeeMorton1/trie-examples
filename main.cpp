//
// Created by conner on 4/2/21.
//
#define CATCH_CONFIG_RUNNER
//#include "catch_amalgamated.hpp"
#include "catch_amalgamated.cpp"
#include <iostream>

struct node //Structure for each node
{
    struct node *children[26]; // The children of the possible characters in the alphabet (Only working with lowercase letters)
    bool isCompleteWord; //To tell if the ndoe is a complete word, useful for many different applications
};

struct node *getNode()//Generate a new node and set the values to null of all childrena dn the current node
{
    auto *curr =  new node;

    curr->isCompleteWord = false;

    for (auto & i : curr->children)
        i = nullptr;

    return curr;
}
void insert(struct node *root, const std::string& key) //Inert into the trie
{
    struct node *curr = root; //set equal to the root

    for (char i : key) //Iterate over each character in the key
    {
        int index = i - 'a'; //subtract the value of 'a' to get the int value of the character so it takes up less space but represents the same concept
        if (!curr->children[index]) //if there is null at the
            curr->children[index] = getNode();

        curr = curr->children[index];
    }


    curr->isCompleteWord = true;
    std::cout<<"Successfuly inserted "<<key<<std::endl;
}

bool search(struct node *root, const std::string& key)
{
    struct node *curr = root;

    for (char i : key)
    {
        int index = i - 'a';
        if (!curr->children[index])
            return false;

        curr = curr->children[index];
    }

    return (curr != nullptr && curr->isCompleteWord);
}
TEST_CASE("Trie works","[trie]"){
    struct node* root = getNode();
    insert(root,"bead");
    insert(root,"bell");
    insert(root,"become");
    insert(root,"benign");
    insert(root,"befall");
    insert(root,"behold");
    insert(root,"antidote");
    insert(root,"antithesis");
    insert(root,"antibiotic");
    insert(root,"antisocial");
    insert(root,"antipathy");

    REQUIRE(search(root,"antidote")==true);
    REQUIRE(search(root,"antipathy")==true);
    REQUIRE(search(root,"trie")==false);
    REQUIRE(search(root,"behold")==true);

}

//int main(){
//
//    struct node* root = getNode();
//    insert(root,"bead");
//    insert(root,"bell");
//    insert(root,"become");
//    insert(root,"benign");
//    insert(root,"befall");
//    insert(root,"behold");
//    insert(root,"antidote");
//    insert(root,"antithesis");
//    insert(root,"antibiotic");
//    insert(root,"antisocial");
//    insert(root,"antipathy");
//
//    std::cout.setf(std::ios::boolalpha);//Make sure output is false/true instead of 0 or 1
//
//    std::cout<<"Begin searching trie";
//    std::cout<<std::endl<<std::endl;
//
//    std::cout<<"antidote is found?  "<<search(root,"antidote")<<std::endl; //Search for antidote
//
//    std::cout<<"behold is found ?  "<<search(root,"behold")<<std::endl;
//    std::cout<<"trie is found ?  "
//
//    return 0;
//}