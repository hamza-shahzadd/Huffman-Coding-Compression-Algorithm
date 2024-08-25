#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class NodeT //class of treeNode
{
public:
	NodeT* left;
	NodeT* right;
	int freq;
	char valf;

	NodeT(int f, char s)
	{

		left = NULL;
		right = NULL;
		freq = f;
		valf = s;
	}
};


class NodeQ //class of queueNode
{
public:

	NodeT* num;
	NodeQ* next;
	NodeQ* prev;
	NodeQ(NodeT* n)
	{
		num = n;
		prev = NULL;
		next = NULL;
	}
};

class QueueImplementation
{
public:

	NodeQ* front;
	NodeQ* rear;
	int size;

	QueueImplementation()
	{
		front = NULL;
		rear = NULL;
		size = 0;
	}
	// adding a node into a queue
	void enqueue(NodeT* val)
	{
		//Create a dynamic node
		NodeQ* newnode = new NodeQ(val);
		newnode->num = val;

		if (front == NULL)
		{
			// When adding a first node of queue
			front = newnode;
			rear = newnode;
		}
		else
		{
			NodeQ* temp = rear;

			newnode->prev = temp;

			temp->next = newnode;

			newnode->prev->next = newnode;
			rear = newnode;
		}

		size = size + 1;
	}
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	NodeT* peek()
	{
		if (isEmpty() == true)
		{
			// When Queue is empty
			cout << "The queue is empty" << endl;
			return NULL;
		}
		else
		{
			return front->num;
		}
	}
	int Size()
	{
		return this->size;
	}
	// Remove a front node of a queue
	void dequeue()
	{
		if (isEmpty() == false)
		{
			NodeQ* temp = front;
			if (front == rear)
			{
				// When queue has only one node
				rear = NULL;
				front = NULL;
			}
			else
			{
				front = front->next;
				front->prev = NULL;
			}
			temp->num = NULL;
			delete temp;

			size--;
		}
	}
	// Print elements of queue
	void DisplayQdata()
	{
		NodeQ* node = front;
		float num = 0;
		float count = 0;
		float ratio;
		cout << "The Queue Elements are: ";

		do
		{
			cout << "\n " << node->num->freq << " " << node->num->valf;
			node = node->next;
		}

		while (node != NULL);


		cout << endl;
	}
};

class Priority_Queue
{
public:

	NodeQ* front;
	NodeQ* rear;
	int size;
	int queuevar;
	bool checking;
	double sumqueue;


	Priority_Queue()
	{
		front = NULL;
		rear = NULL;
		size = 0;
	}
	// Add a node into queue Priority queue
	void enQueueP(NodeT* auxN)
	{

		//Create a dynamic node
		NodeQ* nodeN = new  NodeQ(auxN);
		nodeN->num = auxN;
		if (front == NULL)
		{
			// When adding a first node of queue
			front = nodeN;
			rear = nodeN;
		}
		else if (front->num->freq >= auxN->freq)
		{
			// Add node at beginning position
			nodeN->next = front;
			front->prev = nodeN;
			front = nodeN;
		}
		else if (rear->num->freq <= auxN->freq)
		{
			// Add node at last position
			nodeN->prev = rear;
			rear->next = nodeN;
			rear = nodeN;
		}
		else
		{
			NodeQ* temp = front;


			do
			{
				temp = temp->next; //traversing the queue
			}

			while (temp->num->freq < auxN->freq);


			int bits = 0;
			// Adding new node
			nodeN->next = temp;
			checking = true;

			nodeN->prev = temp->prev;

			for (int j = 0; j <= queuevar; j++)
			{
				sumqueue += sumqueue;
			}
			temp->prev = nodeN;

			sumqueue--;
			if (nodeN->prev != NULL)
			{
				checking = true;
				nodeN->prev->next = nodeN; // the previous pointer become new node
			}

			int frontqueue = -1;
		}

		size = size + 1; //inc 1
	}
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	NodeT* peek()
	{
		if (this->isEmpty() == true)
		{
			// When Queue is empty
			cout << "The queue is empty" << endl;
			return NULL;
		}
		else
		{
			return front->num;
		}
	}
	int Size()
	{
		return size;
	}
	// Remove a front node of a queue
	void deQueueP()
	{
		if (isEmpty() == false)
		{
			NodeQ* temp = front;
			if (front == rear)
			{
				// When queue contains only one node
				rear = NULL;
				front = NULL;
			}
			else
			{
				front = front->next;
				front->prev = NULL;
			}
			temp->num = NULL;
			delete temp;

			size--;
		}
	}
	// to display elements of queue
	void DisplayPQdata()
	{
		NodeQ* noden = front;
		float num = 0;
		float counter = 0;
		float ratio;
		cout << "The Queue Element: ";

		do {
			cout << "\n " << noden->num->freq << " " << noden->num->valf;
			noden = noden->next;
		} while (noden != NULL);

		cout << endl; ;
	}
};
class HuffmanCoding
{
public:

	double sumvar = 0.0; //to sum the values
	int huffC;      //store the huff scheme
	bool check;   //for true false
	int inst;




	// Display Huffman code
	void DisplayTree(NodeT* node, string ans, int* count)
	{
		int tem = 0;

		if (node == NULL)
		{
			return;
		}

		if (node->left == NULL && node->right == NULL)
		{
			tem = tem + ans.length();
			tem = tem * node->freq;

			*count += tem;



			cout << "\n " << node->valf << " " << ans;


			return;
		}

		DisplayTree(node->left, ans + "0", count);
		DisplayTree(node->right, ans + "1", count);
	}


	//huffman tree
	NodeT* HuffmanTree(char value[], int freqH[], int number)
	{
		Priority_Queue temp = Priority_Queue();
		int counting = 0;

		huffC++;
		NodeT* root = NULL;
		sumvar += sumvar;
		NodeT* num1 = NULL;
		for (int i = 0; i <= sumvar; i++)
		{
			huffC;
		}
		NodeT* num2 = NULL;

		//now for adding the numbers into the queue

		for (int i = 0; i < number; ++i)
		{
			root = new NodeT(freqH[i], value[i]);

			inst--; // dec 1 each time to traverse

			temp.enQueueP(root);
		}

		do {


			check = true;
			num1 = temp.peek();

			huffC *= sumvar + inst;
			//Remove a first element
			temp.deQueueP();

			while (sumvar > 3)
			{
				inst--;
			}
			// Get second  node small
			num2 = temp.peek();

			// Remove a front element
			temp.deQueueP();
			// Make new node using two smallest node
			sumvar--; //when we dequeue any value the sum var is decremented

			root = new NodeT(num1->freq + num2->freq, ' ');

			counting++;
			// Add new node into priority queue
			temp.enQueueP(root);

			// left and right child as root
			root->left = num1;

			check = true;  //cond satisfied

			root->right = num2; // store the value of num2 onto the root
		}
		// Execute loop till 1 left
		while (temp.Size() > 1);

		temp.deQueueP();
		return root;
	}
};



class HuffmanCodingT1
{
public:
	// Display Huffman code
	void DisplayTree(NodeT* node, string answer, int* count1)
	{
		int t = 0;
		if (node == NULL)
		{
			return;
		}

		if (node->left == NULL && node->right == NULL)
		{
			t = t + answer.length();
			t = t * node->freq;
			*count1 += t;
			if (node->valf != '\0')
				cout << "\n " << node->valf << " " << answer;
			return;
		}


		DisplayTree(node->left, answer + "0", count1);
		DisplayTree(node->right, answer + "1", count1);
	}
	// the huffman coding Tree
	NodeT* Huffman(char value[], int frequency[], int nuw)
	{
		QueueImplementation ptr = QueueImplementation();
		NodeT* root = NULL;
		NodeT* NUM1 = NULL;
		NodeT* NUM2 = NULL;
		NodeT* temp;
		// adding all the elements in the queue
		for (int i = 0; i < nuw; ++i)
		{
			root = new NodeT(frequency[i], value[i]);
			ptr.enqueue(root);
			temp = new NodeT(0, '\0');
			ptr.enqueue(temp);
		}


		do

		{
			// Get first smallest node
			NUM1 = ptr.peek();

			ptr.dequeue();
			// Get second smallest node
			NUM2 = ptr.peek();
			// Remove a front element
			ptr.dequeue();
			// Make new node using two smallest node
			root = new NodeT((NUM1->freq + NUM2->freq) / 2, ' ');

			// Add new node into priority queue
			ptr.enqueue(root);

			// Set left and right child
			root->left = NUM1;
			root->right = NUM2;
		}

		while (ptr.Size() > 1);

		ptr.dequeue();
		return root;
	}
};

int main()
{
	int* frequency = new int;

	char* value = new char;

	HuffmanCodingT1 task1 = HuffmanCodingT1();
	HuffmanCoding task2 = HuffmanCoding();

	cout << "Please enter the name of your file:" << endl;
	string file;
	cin >> file;

	ifstream fin(file);

	int size = 0;
	int xx = 0;

	getline(fin, file, '\0');

	for (int i = 0; file[i] != '\0'; i++)
	{
		bool present = false;
		int  index = -1;

		for (int j = 0; j < size && present == false; j++)
		{
			if (file[i] == value[j])
			{
				present = true;
				index = j;
			}
		}

		if (present == true)
		{
			frequency[index]++;
		}
		else
		{
			if (size > 0)
			{
				int* inttemp = new int[size];
				for (int j = 0; j < size; j++)
				{
					inttemp[j] = frequency[j];
				}

				size++;

				frequency = new int[size];

				for (int j = 0; j < size - 1; j++)
				{
					frequency[j] = inttemp[j];
				}
			}
			else
			{
				size++;
			}





			frequency[size - 1] = 1;

			size--;

			char* chartemp = new char[size];
			for (char j = 0; j < size; j++)
			{
				chartemp[j] = value[j];
			}

			size++;
			value = new char[size];

			for (char j = 0; j < size - 1; j++)
			{
				value[j] = chartemp[j];
			}

			value[size - 1] = file[i];
		}
		xx++;
	}

	cout << endl;

	NodeT* root1 = task1.Huffman(value, frequency, size);
	int count1 = 0;
	cout << "* TASK 1 *" << endl;
	task1.DisplayTree(root1, "", &count1);
	double ratio1 = 0;

	//cout << endl << "size =   " << size << "| " << xx << endl;
	ratio1 = (float)(xx * 8) / count1;
	cout << endl << "The compression ratio is:" << endl;
	cout << ratio1 << endl;

	cout << "**********************" << endl;
	cout << endl;

	NodeT* root = task2.HuffmanTree(value, frequency, size);
	int count = 0;

	cout << endl << "* TASK 2 *" << endl;
	task2.DisplayTree(root, "", &count);

	double ratio = 0;

	ratio = (float)(xx * 8) / count;

	cout << endl << "The Optimal compression ratio is:" << endl;
	cout << ratio;
}