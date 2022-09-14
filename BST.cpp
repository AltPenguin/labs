#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Создаем веточку
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


// Тпрямой траверс
void inorder(struct node *root) {
  if (root != NULL) {
    // левый
    inorder(root->left);

    // корневой
    cout << root->key << " -> ";

    // правый
    inorder(root->right);
  }
}

// Вклиниваем узелок
struct node *insert(struct node *node, int key) {
  // Возвращаем новый узелок, если дерево голенькое
  if (node == NULL) return newNode(key);

  // Прыгаем в нужное место и и вставляем узелок
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Ищем наследника прямого траверса
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // А где крайний левый?
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Удаляем узелок, лишним он был
struct node *deleteNode(struct node *root, int key) {
  // Дерево пустое? Ладно, возвращаем узелок
  if (root == NULL) return root;

  // Ищем узелок, который всё-таки удалим (управляем судьбами узелков, хихихи)
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // Если узелок одинок или есть один потомок, то:
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Если узелок порядочный семьянин с двумя потомками, то:
    struct node *temp = minValueNode(root->right);

    // Перемещаем преемника на место удаляемого (будем скучать по нему)
    root->key = temp->key;

    /* Мы удаляем узелок, а он говорит нам уже погруженный по пояс в корзину - 
    Послушай, Роза. Ты не утонешь. Ты останешься жить. 
    И у тебя будет мноого ребятишек. И ты увидишь, как они вырастут. 
    Ты умрешь старой, старой женщиной, в теплой постели. Но не здесь. 
    Не этой ночью. И не сейчас. Ты поняла меня?*/
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Исполнение
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Прямой: ";
  inorder(root);

  cout << "\nПосле удаления 10\n";
  root = deleteNode(root, 10);
  cout << "Прямой: ";
  inorder(root);
}