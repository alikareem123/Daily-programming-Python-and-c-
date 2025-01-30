#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Tree {
public:
	string value;
	int lockerId;
	Tree *parent;
	vector<Tree*> children;
	bool is_locked;
	int locked_descendants;
	bool is_busy;

	Tree(string val) {
		value = val;
		parent = nullptr;
		is_locked = false;
		lockerId = -1;
		locked_descendants = 0;
		is_busy = false;
	}
	Tree* root = new Tree("World");

	bool canLock(Tree* node)
	{
		Tree *current = node->parent;
		while (current != nullptr)
		{
			if (current->is_locked || current->is_busy)
			{
				return false;
			}
			current = current->parent;
		}

		if(node->locked_descendants == 0) {
			return true;
		} else {
			return false;
		}
	}

	bool lock(string X, int uuid) {
		Tree *node = bfs(X);
		if (node->is_locked) {
			return false;
		}
		if(canLock(node)) {
			node->is_busy = true;
		    node->is_locked = true;
		    node->lockerId = uuid;
		    Tree* current = node->parent;
		    while (current != nullptr)
            {
                current->locked_descendants += 1;
                current = current->parent;
            }
			node->is_busy = false;
            return true;
		}
		
		return false;
	}
	bool unlock(string X, int uuid)
    {
        Tree *node = bfs(X);
        if (!node->is_locked)
        {
            return false;
        }
        if (node->lockerId == uuid)
        {
            node->is_locked = false;
            Tree *current = node->parent;
            while (current != nullptr)
            {
                current->locked_descendants -= 1;
                current = current->parent;
            }
            return true;
        }
        return false;
    }
    
    bool upgradeLock(string X, int uuid) {
        Tree *node = bfs(X);
        if(node->is_locked || node->locked_descendants == 0) {
            return false;
        }
		node->is_busy = true;
        if(bfsId(node, uuid)){
            node->is_locked = true;
            Tree* current = parent;
            while (current != nullptr) {
                current->locked_descendants -= locked_descendants;
                current = current->parent;
            }
            node->locked_descendants = 0;
			node->is_busy = false;
            return true;
        }
		node->is_busy = false;
        return false;
    }
    
	Tree* bfs(string X) {
		queue<Tree*> q;
		q.push(root);

		while(!q.empty()) {
			Tree* current = q.front();
			q.pop();
			if (current->value == X) {
				return current;
			}
			for (Tree* child: current->children) {
				q.push(child);
			}
		}
	}
	bool bfsId(Tree* node, int uuid) {
		queue<Tree*> q;
		q.push(node);

		while(!q.empty()) {
			Tree* current = q.front();
			q.pop();
			if (current->is_locked && current->lockerId != uuid) {
				return false;
			}
			if(current->is_locked){
			    current->is_locked = false;
			}
			for (Tree* child: current->children) {
				q.push(child);
			}
		}
		return true;
	}
};