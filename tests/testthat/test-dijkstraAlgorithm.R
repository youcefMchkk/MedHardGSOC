adj_matrix = matrix (c (0 , 4 , 1 , 0 , 0 ,
                        0 , 0 , 0 , 1 , 0 ,
                        0 , 2 , 0 , 5 , 0 ,
                        0 , 0 , 0 , 0 , 3 ,
                        0 , 0 , 0 , 0 , 0),
                     nrow = 5 , ncol = 5 , byrow = TRUE)

# the starting vertex is vertex 0
expected_result = matrix (c(0 , 3 , 1 , 4 , 7 , -1 , 2 , 0 , 1 , 3) , nrow = 2, byrow = TRUE)

test_that("if dijakstra algorithm works", {
  expect_equal(dijkstraAlgorithm(adj_matrix = adj_matrix, starting = 0), expected_result)
})
