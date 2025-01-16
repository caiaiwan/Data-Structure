#pragma once

class AdjacencyMatrix {

public:
	AdjacencyMatrix(int size);
	~AdjacencyMatrix();
	void addEdge(int u, int v, int w);
	void printMatrix() const;
private:
	int m_vertices;
	int** m_edges;
	
};
