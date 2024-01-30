class ThroneInheritance {
private:
    struct Node {
        std::string name;
        Node* parent;
        bool dead;
        std::vector<Node*> children;

        Node(std::string name, Node* parent) : name(name), parent(parent), dead(false) {}

        void addChild(Node* node) {
            children.push_back(node);
        }

        void die() {
            dead = true;
        }

        void inorder(std::vector<std::string>& result) {
            if (!dead) result.push_back(name);

            for (Node* child : children) {
                child->inorder(result);
            }
        }
    };

    Node* king;
    std::unordered_map<std::string, Node*> map;

public:
    ThroneInheritance(std::string kingName) {
        king = new Node(kingName, nullptr);
        map[kingName] = king;
    }

    void birth(std::string parentName, std::string childName) {
        Node* parent = map[parentName];
        Node* child = new Node(childName, parent);

        parent->addChild(child);
        map[childName] = child;
    }

    void death(std::string name) {
        map[name]->die();
    }

    std::vector<std::string> getInheritanceOrder() {
        std::vector<std::string> result;
        king->inorder(result);
        return result;
    }
};
