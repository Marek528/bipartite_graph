#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

bool loadMatrix(const std::string &filename, int &n, std::vector<std::vector<int>> &matrix)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "File not found: " << filename << std::endl;
        return false;
    }

    file >> n;
    
    std::string temp;
    std::getline(file, temp);

    matrix.resize(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        std::string line;
        if (!std::getline(file, line) || line.length() < n)
        {
            std::cout << "Error reading matrix at row " << i << std::endl;
            return false;
        }

        for (int j = 0; j < n; j++)
        {
            // when removing char '0' from '0' in ASCII it is 48 - 48 = 0; same with 1 -> 49('1') - 48('0') = 1
            matrix[i][j] = line[j] - '0';
        }
    }
    
    return true;
}

bool isBipartite(const std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    std::vector<int> groups(n, -1);

    for (int start = 0; start < n; start++)
    {
        if (groups[start] != -1)
        {
            continue;
        }
        
        std::queue<int> q;
        q.push(start);
        groups[start] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbour = 0; neighbour < n; neighbour++)
            {
                if (matrix[curr][neighbour] == 1)
                {
                    // if not visited -> assign to the opposite group and push neighbour to the queue to continue through graph
                    // if visited -> check if it is in the same group -> if yes -> its not bipartite
                    if (groups[neighbour] == -1)
                    {
                        groups[neighbour] = !groups[curr];
                        q.push(neighbour);
                    }
                    else if (groups[neighbour] == groups[curr])
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename.txt>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int n;
    std::vector<std::vector<int>> M;

    if (!loadMatrix(filename, n, M))
    {
        return 1;
    }

    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }

    bool result = isBipartite(M);
    std::cout << std::endl << (result ? "graph is bipartite" : "graph is not bipartite");

    return 0;
}