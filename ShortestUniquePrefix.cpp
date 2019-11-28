/*
Shortest Unique Prefix
Find shortest unique prefix to represent each word in the list. Example:
Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
*/

// Create trie of string, for each node keep track of freq the number of time node has been visited for finding prefix check if the count is 1 and return

struct Trie
{ // Struct to create trie
    int count;
    Trie *child[26];
};

struct Trie *trieNode(void)
{ // Function to initialize trie node with child and assign null to them and return the node

    struct Trie *new_trie = new Trie;
    new_trie->count = 1;
    for (int i = 0; i < 26; i++)
    {
        new_trie->child[i] = NULL;
    }
    return new_trie;
}

void insert(Trie *root, string s)
{ // Insert strings into Trie
    struct Trie *step = root;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 'a';
        if (!step->child[idx]) // if node doesnt exist create new node with its child
            step->child[idx] = trieNode();
        else
            (step->child[idx]->count)++; // else inc the count of the child node
        step = step->child[idx];         // move to child node
    }
}

string findPrefix(Trie *root, string s)
{ //Function to find prefix

    Trie *temp = root;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    { //check till string length
        int c = s[i] - 'a';
        root = root->child[c]; // move to character node
        ans += s[i];           // add to result
        if (root->count == 1)  // if current node freq is one return
            return ans;
    }
}
vector<string> Solution::prefix(vector<string> &A)
{

    struct Trie *root = trieNode(); // Call function to create root node, with all its child initialized to NULL
    for (auto a : A)
    {
        insert(root, a);
    }

    vector<string> res;
    for (auto a : A)
    {
        res.emplace_back(findPrefix(root, a)); //Calling fndPrefix to get result and store in vector for each string
    }

    return res;
}
