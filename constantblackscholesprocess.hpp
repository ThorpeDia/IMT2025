#ifndef CONSTANTBLACKSCHOLSPROCESS_HPP
#define CONSTANTBLACKSCHOLSPROCESS_HPP

#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    //! Black-Scholes process with constant parameters.
    class ConstantBlackScholesProcess : public StochasticProcess1D {
      public:
        ConstantBlackScholesProcess(double underlyingValue,
                                    double riskFreeRate,
                                    double volatility,
                                    double dividend);
        Real x0() const override;
        Real drift(Time t, Real x) const override;
        Real diffusion(Time t, Real x) const override;
        Real apply(Real x0, Real dx) const override;
      private:
        double underlyingValue_;
        double riskFreeRate_;
        double volatility_;
        double dividend_;
    };

}

#endif
