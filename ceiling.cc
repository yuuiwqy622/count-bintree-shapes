#include <cstdio>
#include <memory>
#include <set>
#include <string>

struct Node {
  std::shared_ptr<Node> children[2];
  int val;

  Node(int val) : children{nullptr, nullptr}, val(val) {}

  static std::string ToString(std::shared_ptr<Node> n) {
    if (!n)
      return "";

    return "(" + ToString(n->children[0]) + "-" + ToString(n->children[1]) +
           ")";
  }

  static std::shared_ptr<Node> Add(std::shared_ptr<Node> n, int val) {
    if (!n)
      return std::make_shared<Node>(val);

    bool idx = val > n->val;
    n->children[idx] = Add(n->children[idx], val);
    return n;
  }
};

int main(void) {
  int n, k;

  while (true) {
    if (scanf("%d %d", &n, &k) != 2)
      return 0;

    std::set<std::string> shapes;
    while (n--) {
      std::shared_ptr<Node> tree = nullptr;

      for (int i = 0; i < k; ++i) {
        int v;
        scanf("%d", &v);
        tree = Node::Add(tree, v);
      }

      shapes.insert(Node::ToString(tree));
    }

    printf("%lu\n", shapes.size());
  }

  return 0;
}