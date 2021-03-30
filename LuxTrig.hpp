namespace Lux
{
    using f32 = float;
    using f64 = double;

    namespace Math
    {
        constexpr f32 PI32 = 3.14159265358979323846f;

        constexpr f64 PI64 = 3.14159265358979323846;

        constexpr f32 DoublePI32 = PI32 * 2.f;

        constexpr f64 DoublePI64 = PI64 * 2.;

        constexpr f32 HalfPI32 = PI32 * .5f;

        constexpr f64 HalfPI64 = PI64 * .5;

        namespace Trigonometry
        {
            [[nodiscard]] inline constexpr f32 Sine(f32 x) noexcept
            {
                if(x > PI32)
                    x -= DoublePI32;
                const f32 x2 = x * x;
                return ((0.0000027181216275479732f * x2 - 0.00019839312269456257f) * x2 * x2 + (0.0083333293048425631f * x2 - 0.16666666640797048f)) * x2 * x + x;
            }

            [[nodiscard]] inline constexpr f64 Sine(f64 x) noexcept
            {
                if(x > PI64)
                    x -= DoublePI64;
                const f64 x2 = x * x;
                return ((0.0000027181216275479732 * x2 - 0.00019839312269456257) * x2 * x2 + (0.0083333293048425631 * x2 - 0.16666666640797048)) * x2 * x + x;
            }

            [[nodiscard]] inline constexpr f32 Cosine(f32 x) noexcept
            {
              return Sine(x + HalfPI32);
            }

            [[nodiscard]] inline constexpr f64 Cosine(f64 x) noexcept
            {
                return Sine(x + HalfPI64);
            }
        }
    }
}
