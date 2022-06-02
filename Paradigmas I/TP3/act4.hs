-- *
-- * Definir las siguiente funciones: N siguiente y anterior N, que retorne el numero correlativo según el nombre de la funcion
-- *
-- *

current :: Int -> (Int, Int)
current n = (n + 1, n - 1)

main = do
  let n = 7
  print("N = " ++ show n)
  putStrLn $ concat ["-" | i <- [1..20]]

  -- Prelude module
  -- * fst returns the first item in a tuple
  putStrLn("Siguiente: " ++ show (fst (current n)))

  -- * snd returns the second item in a tuple
  putStrLn("Anterior: " ++ show (snd (current n)))