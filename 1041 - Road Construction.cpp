#define ACTIVE
#define _CRT_SECURE_NO_WARNINGS
#ifdef ACTIVE


#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<cstdio>


using namespace std;


int min(int x, int y) {
	if (x <= y) return x;
	return y;
}


template<typename T>
T** new2D(size_t max_r, size_t max_c, T initVal = NULL);

template<typename T>
void delete2D(T** mat, size_t max_r);


#define NULL_VALUE -999999
#define INFINITY 999999

#define NIL -1


//****************Heap start************************
#pragma region MINHEAP



#define MAX_HEAP_SIZE 100000+1

template <typename T> class HeapItem
{
public:
	T data;
	int key;
};


template <typename T> class MinHeap
{

public:
	MinHeap();
	~MinHeap();

	T MIN();
	T Extract_MIN();




	void Insert(T data, int key);

	bool IncreaseKey(int i, int key);
	bool DecreaseKey(int i, int key);

	size_t size();

	void BuildHeap(T Array[], int key[], int size);

	bool hasItem(T data);
	int getPos(T data);

	bool isEmpty();

	int getKey(T data);



	void PrintHeap()
	{
		for (int i = 1; i <= heap_size; i++)
		{
			cout << "---" << i << " === " << map[A[i].data] << "---" << A[i].data << "---" << A[i].key << endl;
		}
	}
protected:
	HeapItem<T>* A = NULL;
	int *map = NULL;
	size_t heap_size;

	void heapify_UpBottom(int i);
	void heapify_BottomUp(int i);

	int left(int i);
	int right(int i);
	int parent(int i);

	void swap(HeapItem<T>& x, HeapItem<T>& y);
	//void swap(int& x, int& y);

	bool smaller(HeapItem<T>& x, HeapItem<T>& y);
};


template <typename T>
MinHeap<T>::MinHeap()
{
	A = new HeapItem<T>[MAX_HEAP_SIZE];
	map = new int[MAX_HEAP_SIZE];
	memset(map, NULL, MAX_HEAP_SIZE * sizeof(int));
	heap_size = 0;
}


template <typename T>
MinHeap<T>::~MinHeap()
{
	if (A) delete[] A;
	if (map) delete[] map;
	heap_size = 0;
	A = NULL;
	map = NULL;
}



template <typename T>
void MinHeap<T>::Insert(T data, int key)
{
	heap_size = heap_size + 1;
	A[heap_size].data = data;
	A[heap_size].key = key;
	map[data] = heap_size;
	heapify_BottomUp(heap_size);
}

template<typename T>
T MinHeap<T>::Extract_MIN()
{
	if (!heap_size)
		return T(NULL);
	else {
		//cout << "Before Xtract ::: " << endl;
		//PrintHeap();
		T x = A[1].data;
		//map[A[1].data] = NULL;
		swap(A[1], A[heap_size]);
		heap_size = heap_size - 1;
		heapify_UpBottom(1);
		map[x] = NULL;
		//cout << "After Xtract ::: " << endl;
		//PrintHeap();
		return x;
	}
}

template<typename T>
T MinHeap<T>::MIN()
{
	if (isEmpty()) return T(NULL);
	else return A[1].data;
}


template<typename T>
void MinHeap<T>::heapify_BottomUp(int i)
{
	if (i > heap_size)	return;

	while (i > 1 && smaller(A[i], A[parent(i)]))
	{
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}

template<typename T>
void MinHeap<T>::heapify_UpBottom(int i)
{
	if (i<1 || i > heap_size) return;

	int smallest = 0;

	int l = left(i), r = right(i);

	if (l <= heap_size && smaller(A[l], A[i]))
		smallest = l;
	else
		smallest = i;

	if (r <= heap_size && smaller(A[r], A[smallest]))
		smallest = r;

	if (smallest != i) {
		swap(A[i], A[smallest]);
		heapify_UpBottom(smallest);
	}
}


template<typename T>
bool MinHeap<T>::IncreaseKey(int i, int key)
{
	HeapItem<T> updated;
	updated.data = A[i].data;
	updated.key = key;
	if (smaller(updated, A[i]))
		return false;
	else
	{
		A[i].key = key;
		heapify_UpBottom(i);
		return true;
	}
}

template<typename T>
bool MinHeap<T>::DecreaseKey(int i, int key)
{
	HeapItem<T> updated;
	updated.data = A[i].data;
	updated.key = key;
	if (!smaller(updated, A[i]))
		return false;
	else
	{
		A[i].key = key;
		heapify_BottomUp(i);
		return true;
	}
}















template<typename T>
size_t MinHeap<T>::size()
{
	return heap_size;
}

template<typename T>
void MinHeap<T>::BuildHeap(T Array[], int key[], int size)
{
	heap_size = size;
	for (size_t i = 1; i <= heap_size; i++)
	{
		A[i].data = Array[i - 1];
		A[i].key = key[i - 1];

		map[A[i].data] = i;
	}

	for (size_t i = heap_size / 2; i > 0; i--)
	{
		heapify_UpBottom(i);
	}
}

template<typename T>
bool MinHeap<T>::hasItem(T data)
{
	return map[data];
}

template<typename T>
int MinHeap<T>::getPos(T data)
{
	return map[data];
}

template<typename T>
bool MinHeap<T>::isEmpty()
{
	return !heap_size;
}

template<typename T>
int MinHeap<T>::getKey(T data)
{
	//cout << "----"<<data<<"----" << A[map[data]].key << endl;
	if (!hasItem(data)) return NULL;
	return A[map[data]].key;
}

template<typename T>
int MinHeap<T>::left(int i)
{
	return 2 * i;
}

template<typename T>
int MinHeap<T>::right(int i)
{
	return 2 * i + 1;
}

template<typename T>
int MinHeap<T>::parent(int i)
{
	return i / 2;
}

template<typename T>
void MinHeap<T>::swap(HeapItem<T> & x, HeapItem<T> & y)
{
	T tempData = x.data;
	x.data = y.data;
	y.data = tempData;


	//swap(map[x.data], map[y.data]);
	int t = map[x.data];
	map[x.data] = map[y.data];
	map[y.data] = t;



	int tmpKey = x.key;
	x.key = y.key;
	y.key = tmpKey;
}

//template<typename T>
//void MinHeap<T>::swap(int & x, int & y)
//{
//	int t = x;
//	x = y;
//	y = t;
//}






template<typename T>
bool MinHeap<T>::smaller(HeapItem<T>& x, HeapItem<T>& y)
{
	if (x.key < y.key) return true;
	else if (x.key == y.key && x.data < y.data) return true;
	return false;
}


#pragma endregion
//****************Heap end************************






class Edge
{
public:
	int v = -1;
	int w = 0;
	bool operator==(Edge edg2)
	{
		return v == edg2.v;
	}

	Edge(int v = -1) { this->v = v; }
	Edge(int v, int w) { this->v = v; this->w = w; }
};

















#pragma region GRAPH


#define WHITE 1 // NOT VISITED
#define GREY 2 // DISCOVERED
#define BLACK 3 // VISITED



#define EDGE_Y 1
#define EDGE_N NIL


#define ADJ_LIST_TYPE vector<Edge>
#define ADJLISTPOS vector<Edge>::iterator

//******************Graph class starts here**************************
class Graph
{
	bool directed;
	bool startAt1;
	int W_total;

	ADJ_LIST_TYPE* adjList;


	int *dist;
	int *parent;


	int minCost;

	ADJ_LIST_TYPE::iterator findVInListOfU(int u, int v) {
		return find(adjList[u].begin(), adjList[u].end(), Edge(v));
	}

	bool isNULL(ADJ_LIST_TYPE::iterator it, int u) {
		return it == adjList[u].end();
	}


public:
	int nVertices, nEdges;

	Graph(bool dir = false);
	Graph(const Graph& g);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v, int w);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
	bool hasVertex(int u) { return !(u < 0 || u >= nVertices); }
	int getWeight(int u, int v);
	void setWeight(int u, int v, int w);


	int getDegree(int u);
	bool hasCommonAdjacent(int u, int v);

	int MST_Prim(int source, Graph& Tree);
	int MST_Prim_Execute(Graph& Tree, MinHeap<int>& Q, int key[], int parent[]);

	void printEdges();
};

int Graph::getWeight(int u, int v)
{
	if (hasVertex(u) && hasVertex(v) && isEdge(u, v)) {
		ADJLISTPOS i = findVInListOfU(u, v);
		if (!isNULL(i, u)) return i->w;

	}
	return 0;
}

Graph::Graph(bool dir)
{
	nVertices = 0;
	nEdges = 0;
	W_total = 0;

	adjList = NULL;

	directed = dir; //set direction of the graph
					//define other variables to be initialized

	dist = NULL;
	parent = NULL;

	minCost = 0;
}

Graph::~Graph()
{
	if (nVertices) {
		if (adjList) delete[] adjList; //delete previous list

		delete[] dist, parent;

	}

	adjList = NULL;

	dist = NULL;
	parent = NULL;


	nVertices = 0;
	nEdges = 0;
	W_total = 0;
}



// Set Vertices Numbered from 0 to n
void Graph::setnVertices(int n)
{
	if (nVertices) this->~Graph();

	nVertices = n;

	adjList = new ADJ_LIST_TYPE[nVertices];


	dist = new int[nVertices];
	parent = new int[nVertices];

	W_total = 0;
}

// O(1)
void Graph::addEdge(int u, int v, int w)
{
	if (!hasVertex(u) || !hasVertex(v)) return;
	nEdges++;

	adjList[u].push_back(Edge(v, w));
	if (!directed) adjList[v].push_back(Edge(u, w));


	W_total += w;
}

// MAT-O(1) & LIST-O(deg(V))
void Graph::removeEdge(int u, int v)
{
	if (!hasVertex(u) || !hasVertex(v) || !isEdge(u, v)) return; //vertex out of range
	--nEdges;
	W_total -= getWeight(u, v);

	ADJLISTPOS i = findVInListOfU(u, v);
	if (isNULL(i, u)) return;
	adjList[u].erase(i);
	if (!directed) adjList[v].erase(findVInListOfU(v, u));

}

//returns true if (u,v) is an edge, otherwise should return false
// MAT-O(1) & LIST-O(deg(V))
bool Graph::isEdge(int u, int v)
{
	return hasVertex(u) && hasVertex(v) && !isNULL(findVInListOfU(u, v), u);
}




// MAT-O(deg(V)) & LIST-O(1)
int Graph::getDegree(int u)
{
	//returns the degree of vertex u
	if (!hasVertex(u)) return NIL;

	size_t noOfDeg = 0;
	noOfDeg = adjList[u].size();
	return noOfDeg;
}


// MAT-O(V^2*log(V)) & LIST-O(Elog(V))
int Graph::MST_Prim_Execute(Graph & Tree, MinHeap<int>& Q, int key[], int parent[])
{
	minCost = 0;

	while (!Q.isEmpty())// Q.length = O(V)
	{
		//minCost += Q.getKey(Q.MIN());
		int u = Q.Extract_MIN();// O(log(V))
		minCost += key[u];

		if (parent[u] != NULL_VALUE) {
			//cout << parent[u] << " " << u << endl;
			Tree.addEdge(parent[u], u, getWeight(parent[u], u));

		}

		for (int i = 0, v, w; i < adjList[u].size(); ++i)// O(deg(u))
		{
			v = adjList[u][i].v;
			w = adjList[u][i].w;
			if (Q.hasItem(v) && w < Q.getKey(v)) {
				parent[v] = u;
				key[v] = w;
				Q.DecreaseKey(Q.getPos(v), w);//log(V)
			}
		}

	}
	return minCost;
}

// MAT-O(V^2*log(V)) & LIST-O(Elog(V))
int Graph::MST_Prim(int source, Graph& Tree)
{
	int* key = new int[nVertices];
	Tree.setnVertices(nVertices);
	int *V = new int[nVertices];
	for (size_t u = 0; u < nVertices; u++) {
		key[u] = INFINITY;
		V[u] = u;
		parent[u] = NULL_VALUE;
	}

	MinHeap<int> Q;

	Q.BuildHeap(V, key, nVertices); // O(V)

	Q.DecreaseKey(Q.getPos(source), 0); // O(log(V))
	parent[source] = NULL_VALUE;
	key[source] = 0;

	return MST_Prim_Execute(Tree, Q, key, parent);
}

void Graph::printEdges()
{
	bool **printed = new2D<bool>(nVertices, nVertices, false);

	for (size_t u = 0; u < nVertices; u++)
	{
		for (int v = 0; v < nVertices; ++v)
		{
			if (!printed[u][v] && isEdge(u, v))
			{
				cout << u << " " << v << " " << getWeight(u,v) << endl;
				printed[u][v] = true;
				if (!directed) printed[v][u] = true;
			}
		}
	}

	delete2D<bool>(printed, nVertices);
}

void Graph::setWeight(int u, int v, int w)
{
	W_total -= getWeight(u, v);

	ADJLISTPOS i = findVInListOfU(u, v);
	if (isNULL(i, u)) {
		addEdge(u, v, w);
	}
	else
	{
		i->w = w;
		if (!directed) {
			findVInListOfU(v, u)->w = w;
		}
	}

	W_total += getWeight(u, v);
}


#pragma endregion



template<typename T>
T ** new2D(size_t max_r, size_t max_c, T initVal)
{
	T** mat = new T*[max_r];
	for (size_t i = 0; i < max_r; i++)
	{
		mat[i] = new T[max_c];
		memset(mat[i], initVal, max_c * sizeof(T));
	}
	return mat;
}

template<typename T>
void delete2D(T ** mat, size_t max_r)
{
	for (size_t i = 0; i < max_r; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}




struct EdgeList
{
	int u = -1, v = -1, w = 0;
};

int main()
{
	int t = 0;
	scanf("%d", &t);
	int cs = 0;
	while (cs < t)
	{
		cs++;

		map<string, int> mp;
		bool directed = false;


		Graph g(directed);

		int n, m;
		n = m = 0;

		int u, v, w;
		u = v = w = 0;
		scanf("%d", &m);

		string x, y;

		EdgeList* edgs = new EdgeList[m];
		n = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y >> w;

			if (mp.find(x) == mp.end()) {
				//cout << "Map Size ::: " << mp.size() << endl;
				mp[x] = n++;
				//mp(x, mp.size());
				//cout << "Map Size ::: " << mp.size() << endl;
				//cout << x << " --> " << mp[x] << endl;
			}
			if (mp.find(y) == mp.end()) {
				mp[y] = n++;
				//cout << y << " --> " << mp[y] << endl;
			}
			u = mp[x];
			v = mp[y];

			edgs[i].u = u;
			edgs[i].v = v;
			edgs[i].w = w;
		}
		//n = mp.size();
		g.setnVertices(n);


		for (int i = 0; i < m; ++i)
		{
			u = edgs[i].u;
			v = edgs[i].v;
			w = edgs[i].w;

			g.addEdge(u, v, w);
		}

        //g.printEdges();
		int source = 0;

		Graph MST(directed);

		int minCost = g.MST_Prim(source, MST);
		if (MST.nEdges != MST.nVertices - 1)printf("Case %d: Impossible\n", cs);
		else printf("Case %d: %d\n", cs, minCost);

	}


	return 0;
}



#endif // ACTIVE

