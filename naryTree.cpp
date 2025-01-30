#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    string value;
    TreeNode *parent;
    vector<TreeNode *> children;
    bool is_locked;
    int locked_descendant_count;

    TreeNode(string val)
    {
        value = val;
        parent = nullptr;
        is_locked = false;
        locked_descendant_count = 0;
    }

    bool can_lock_or_unlock()
    {
        TreeNode *current = parent;
        while (current != nullptr)
        {
            if (current->is_locked)
            {
                return false;
            }
            current = current->parent;
        }
        return current->locked_descendant_count == 0;
    }
    bool lock()
    {
        if (islocked())
        {
            return false;
        }
        if (can_lock_or_unlock())
        {
            is_locked = true;
            TreeNode *current = parent;
            while (current != nullptr)
            {
                current->locked_descendant_count += 1;
                current = current->parent;
            }
            return true;
        }
        return false;
    }

    bool unlock()
    {
        if (!islocked())
        {
            return false;
        }
        if (can_lock_or_unlock())
        {
            is_locked = false;
            TreeNode *current = parent;
            while (current != nullptr)
            {
                current->locked_descendant_count -= 1;
                current = current->parent;
            }
            return true;
        }
        return false;
    }

    bool islocked() const
    {
        return is_locked;
    }

    void addChild(TreeNode *childNode)
    {
        childNode->parent = this;
        children.push_back(childNode);
    }

    bool upgrade()
    {
        if (is_locked || locked_descendant_count == 0)
        {
            return false;
        }
        if (areAllDescendantsLocked())
        {
            unlockAllDescendants();

            is_locked = true;
            TreeNode *current = parent;
            while (current != nullptr)
            {
                current->locked_descendant_count -= locked_descendant_count;
                current = current->parent;
            }

            locked_descendant_count = 0;
            return true;
        }
        return false;
    }

    void bfs()
    {
        queue<TreeNode *> q;
        q.push(this);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            for (TreeNode *child : current->children)
            {
                q.push(child);
            }
        }
    }

private:
    bool areAllDescendantsLocked()
    {
        for (auto child : children)
        {
            if (!child->islocked() || !child->areAllDescendantsLocked())
            {
                return false;
            }
        }
        return true;
    }
    void unlockAllDescendants()
    {
        for (auto child : children)
        {
            if (child->islocked())
            {
                child->is_locked = false;
                TreeNode *current = child->parent;
                while (current != nullptr)
                {
                    current->locked_descendant_count -= 1;
                    current = current->parent;
                }
            }
            child->unlockAllDescendants();
        }
    }
};