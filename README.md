# gittools

cet outil doit télécharger un repo git et récursivement tous les sous modules qu'il contient
- sans télécharger les doublons
- mais en prenant systématiquement le commit le plus récent en cas de doublon
- en mettant le répertoire racine de chaque repo à plat sous la racine principale
- éventuellement en construisant l'ancienne

il est écrit en c
il appelle les commandes git
