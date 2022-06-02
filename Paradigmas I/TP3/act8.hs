-- *
-- * Definir la función raices para determinar los valores de la ecuación ax^2+bx+c=0
-- *

raices :: (Float, Float, Float) -> (Float, Float)
raices (a, b, c) = (x1, x2)
    where
      x1 = (-b + sqrt(b^2 - 4*a*c)) / (2 * a)
      x2 = (-b - sqrt(b^2 - 4*a*c)) / (2 * a)

main = do
  let a = 4
  let b = 15
  let c = 2

  let res = raices(a,b,c)

  putStrLn("Raices de la ecuacion " ++ show a ++ "x^2 + " ++ show b ++ "x + " ++ show c ++ " = 0")
  putStrLn("x1: " ++ show (fst(res)))
  putStrLn("x2: " ++ show (snd(res)))
