#include "AdjacencyMatrix.h" 
#include<iostream>
AdjacencyMatrix::AdjacencyMatrix(int size) :m_vertices{ size }, m_edges{new int *[m_vertices]}
{
	int nInf = -1;
	for (int i = 0; i < m_vertices; ++i) {
		m_edges[i] = new int[m_vertices];
		for (int j = 0; j < m_vertices; ++j) {
			m_edges[i][j] = nInf;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	for (int i = 0; i < m_vertices; ++i) {
		delete[] m_edges[i];
	}
	delete[] m_edges;
		
}

void AdjacencyMatrix::addEdge(int u, int v, int w)
{
	m_edges[u][v] = w;
}

void AdjacencyMatrix::printMatrix() const
{
	for (int i = 0; i < m_vertices; ++i) {
		
		for (int j = 0; j < m_vertices; ++j) {
			std::cout << m_edges[i][j] << " ";
		}
		std::cout << '\n';
	}
}
