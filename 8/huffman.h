struct huffmannode
{
    int weight;
    int tag;
    int LeftChild;
    int RightChild;
};
typedef struct huffmannode Huffmannode;

struct huffmantree
{
    int root;
};
typedef struct huffmantree Huffmantree;

void InitHuffmannode(Huffmannode * hfmNode,int tag,int left,int right);
void InitHuffmantree(Huffmantree * hfmTree,int root);
void makeHuffmantree(Huffmantree * hfmTree,int a[],Huffmannode b[],int n);
