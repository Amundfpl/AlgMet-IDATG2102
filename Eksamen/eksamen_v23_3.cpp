//
// Created by amund on 04.12.2024.
//

//a.
bool ersosken(const Node t, const Node* s1, const Node s2){
  if(t){
    if(t->left == s1 || s2 && t-> right == s1 || s2){
      return true;
      }
    bool l = ersosken(t -> left, s1, s2);
    bool r = ersosken(t -> right, s1, s2);
    return l || r;
    }
    return false;
  }

 //b.
void kappTreNedentil(Node* t, const int verdi){
 if(t){
   if(t->ID >= verdi){
     t->ID == nullptr;
   }
   kappTreNedentil(t->left, verdi);
   kappTreNedentil(t->right, verdi);
   }

}
void kappTreNedentil(Node* t, const int verdi){
  if(t){
    if(t-> left && t->left-> ID >= verdi){
      t-> left ->ID == nullptr;
      }
     kappTreNedentil(t-> left, verdi);
    if(t-> right && t->right-> ID >= verdi){
      t-> right ->ID == nullptr;
    }
    kappTreNedentil(t-> right, verdi);
    }
  }
