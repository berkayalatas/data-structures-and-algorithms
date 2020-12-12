def search(root,key):
    if root is None or root.val==key:
        return root

    if root.val < key:
        return search(root.right, key)    

    return search(root.left, key)


class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

def insert(root,key):
    if root is None:
        return Node(key)
    else:
        if root.val == key:                    
            return root
        elif root.val < key:
            root.right = insert(root.right, key)
        elif root.val > key:
            root.left = insert(root.left, key)

    return root                

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)    

r = Node(50)
r = insert(r, 30)
r = insert(r,20)

#inorder(r)

###################################

#Delete Node 
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def inorder(root):
    if root is not None:
        inorder(root.left)
        print(root.key)
        inorder(root.right)

def insert(node, key):
    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    return node

def minValueNode(node):
    current = node

    #loop down to find the leftmost leaf
    while(current.left is not None):
        current = current.left

    return current

def deleteNode(root, key):

    #base case
    if root is None:
        return root

    if key < root.key:
        root.left = deleteNode(root.left, key)

    elif (key > root.key):
        root.right = deleteNode(root.right, key)  

    #if key is same as root's key then this is the node to be delete
    else:

        #node with only one child or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        #node with two children => get the inorder successor 
        # smallest in the right subtree
        temp = minValueNode(root.right)

        #copy the inorder successor's content to this node
        root.key = temp.key

        #Delete the inorder successor
        root.right = deleteNode(root.right , temp.key)

    return root

root = None
root = insert(root, 50)
root = insert(root, 30)
root = insert(root, 20)
root = insert(root, 40)
root = insert(root, 70)
root = insert(root, 60)
root = insert(root, 80)
 
print ("Inorder traversal of the given tree")
inorder(root)
 
print ("\nDelete 20")
root = deleteNode(root, 20)
print ("Inorder traversal of the modified tree")
inorder(root)
 
print ("\nDelete 30")
root = deleteNode(root, 30)
print ("Inorder traversal of the modified tree")
inorder(root)
 
print ("\nDelete 50")
root = deleteNode(root, 50)
print ("Inorder traversal of the modified tree")
inorder(root)      


