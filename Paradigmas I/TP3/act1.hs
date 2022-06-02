-- *
-- * Definir la soniguanles N y M, para determinar si los números dados son iguales
-- *

-- isEqual :: int -> int -> Bool
-- (==) -> isEqual n m = if n == m then True else False

main = do
  let n = 7
  let m = 7

  putStr("Los numeros son iguales: ")
  if n == m
    then putStr("Si")
    else putStr("No")

