![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/Xml_logo.svg/1280px-Xml_logo.svg.png)

# XLMP - Xml Parser

- C Library 

## TODO

- Verifier qu'il y a une balise unique englobante
- Verifier la fermeture de la balise englobante
- Methode pour recuperer une node
- Arreter la lecture a la premiere erreur, fermer la balise englobante et retourner
- Norme
- Freedom for the mallocs

## Nodes

- xmlp->node => node vide, son enfant est la balise englobante du document
- node->child => porte vers le niveau inferieur, premier enfant
- node->next => vers une node de meme niveau, pas de limite
- node->parent => niveau superieur

### Example

- node-child => premier enfant
- node->child->next => deuxieme enfant
- node->child->next->child => enfant du deuxieme enfant
- node->child->next->child->next => deuxieme enfant du deuxieme enfant
- node->child->next->child->next->next => troisieme enfant du deuxieme enfant
- node->child->next->next->child->next => deuxieme enfant du troisieme enfant