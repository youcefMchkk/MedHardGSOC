// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// dijkstraAlgorithm
NumericMatrix dijkstraAlgorithm(NumericMatrix adj_matrix, int starting);
RcppExport SEXP _MedHardGSOC_dijkstraAlgorithm(SEXP adj_matrixSEXP, SEXP startingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type adj_matrix(adj_matrixSEXP);
    Rcpp::traits::input_parameter< int >::type starting(startingSEXP);
    rcpp_result_gen = Rcpp::wrap(dijkstraAlgorithm(adj_matrix, starting));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_MedHardGSOC_dijkstraAlgorithm", (DL_FUNC) &_MedHardGSOC_dijkstraAlgorithm, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_MedHardGSOC(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}