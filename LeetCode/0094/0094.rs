#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}
use std::rc::Rc;
use std::cell::RefCell;


pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    fn inorder(node: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
        if let Some(node) = node {
            let node = node.borrow();
            inorder(node.left.clone(), result);
            result.push(node.val);
            inorder(node.right.clone(), result);
        }
    }

    let mut result = Vec::new();
    inorder(root, &mut result);
    result
}

fn main() {
    // Example usage:
    let mut root = TreeNode::new(1);
    let right = TreeNode::new(2);
    let left_of_right = TreeNode::new(3);

    root.right = Some(Rc::new(RefCell::new(right)));
    if let Some(ref r) = root.right {
        r.borrow_mut().left = Some(Rc::new(RefCell::new(left_of_right)));
    }

    let root = Some(Rc::new(RefCell::new(root)));
    let result = inorder_traversal(root);
    println!("{:?}", result); // Output should be [1, 3, 2]
}