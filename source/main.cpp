#include "DiGraph.h"
#include <iostream>

int main() {
    // === Aufgabe 2: Node testen ===
    Node a(1);
    Node b(2);

    b.add_in_edge(&a);    // a -> b
    a.add_out_edge(&b);   // a -> b

    std::cout << "Node b in_edges: ";
    for (Node* n : b.get_in_edges()) {
        std::cout << n->get_id() << " ";  // sollte 1 ausgeben
    }
    std::cout << "\n";

    std::cout << "Node a out_edges: ";
    for (Node* n : a.get_out_edges()) {
        std::cout << n->get_id() << " ";  // sollte 2 ausgeben
    }
    std::cout << "\n\n";

    // === Aufgabe 3: DiGraph testen ===
    DiGraph g;
    Node* n1 = g.add_node();  // ID 0
    Node* n2 = g.add_node();  // ID 1
    Node* n3 = g.add_node();  // ID 2

    g.add_edge(n1->get_id(), n2->get_id());  // 0 -> 1
    g.add_edge(n2->get_id(), n3->get_id());  // 1 -> 2
    g.add_edge(n1->get_id(), n3->get_id());  // 0 -> 2

    std::cout << "DiGraph Knotenanzahl: " << g.get_node_count() << "\n";

    // Alle Kanten ausgeben
    for (auto& pair : *(g.get_node_map_ptr())) {
        Node* node = pair.second;
        std::cout << "Node " << node->get_id() << " -> ";
        for (Node* target : node->get_out_edges()) {
            std::cout << target->get_id() << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
