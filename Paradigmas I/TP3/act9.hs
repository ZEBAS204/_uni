-- *
-- * Definir una función que tome como parámetro un Lista de números y realice su sumatoria
-- *

sumAll :: [int] -> int
sumAll [] = 0
sumAll (x:xs) = x + sumAll xs

main = do
  let n = [1,2,3,4,5]

  putStr("La suma de los elementos "++ show n ++" de la lista es: " ++ show(sumAll n))