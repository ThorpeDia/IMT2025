#include "constantblackscholesprocess.hpp"
#include <iostream>
#include <ql/processes/eulerdiscretization.hpp>

namespace QuantLib {

    ConstantBlackScholesProcess::ConstantBlackScholesProcess(double underlyingValue,
                                                             double riskFreeRate,
                                                             double volatility,
                                                             double dividend)
        : StochasticProcess1D(ext::make_shared<EulerDiscretization>()),
          underlyingValue_(underlyingValue), riskFreeRate_(riskFreeRate),
          volatility_(volatility), dividend_(dividend)
    {}

    Real ConstantBlackScholesProcess::x0() const {
        return underlyingValue_;
    }

    Real ConstantBlackScholesProcess::drift(Time t, Real x) const {
        return riskFreeRate_ - dividend_ - 0.5 * volatility_ * volatility_;
    }

    Real ConstantBlackScholesProcess::diffusion(Time t, Real x) const {
        return volatility_;
    }

    Real ConstantBlackScholesProcess::apply(Real x0, Real dx) const {
        return x0 * std::exp(dx);
    }

}
