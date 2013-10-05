TuhSenrab
=========

Se trata de una implementación del método de Barnes-hut para la simulación de problemas n-body. Consiste en la creación de un árbol 4-ario o quad-tree: un árbol donde cada nodo tiene cero o cuatro nodos hijos. Cada nodo representará un cuadrante y dentro de los cuadrantes se encuentran los cuerpos que son objeto del estudio.

El problema consiste en calcular las interacciones de fuerzas entre los cuerpos sin necesidad de ir utilizando la clásica fórmula en la que se calcula dos a dos. Para N cuerpos estos conlleva a una complejidad O(N^2) pues cada nodo calculará su interacción con cada uno de los otros cuerpos: N*(N-1). Con Barnes-hut se reduce esta complejidad a O(N*LogN).
