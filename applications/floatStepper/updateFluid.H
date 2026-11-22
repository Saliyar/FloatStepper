U.correctBoundaryConditions();

// --- Pressure-velocity PIMPLE corrector loop
while (pimple.loop())
{

    #include "alphaControls.H"
    #include "alphaEqnSubCycle.H"

#ifdef FLOATSTEPPER_WAVES2FOAM
    relaxing.correct();
#endif

    mixture.correct();

    #include "UEqn.H"

    // --- Pressure corrector loop
    while (pimple.correct())
    {
        #include "pEqn.H"
    }

    if (pimple.turbCorr())
    {
        turbulence->correct();
    }
}
